#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *create(int data)
{
    struct node *tree = (struct node *)malloc(sizeof(struct node));
    tree->data = data;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

struct node *insertNode(struct node *root, int data)
{
    if (root == NULL)
        root = create(data);
    else if (data < root->data)
        root->left = insertNode(root->left, data);
    else
        root->right = insertNode(root->right, data);
    return root;
}

float findMedianInBST(struct node *root, int n)
{
    static int count = 0;
    static float evenMid = -1;

    if (root == NULL)
    {
        return -1;
    }

    float leftAns = findMedianInBST(root->left, n);
    count++;

    if (leftAns != -1)
    {
        return leftAns;
    }
    else if (n % 2 != 0 && count == (n + 1) / 2)
    {
        return root->data;
    }
    else if (n % 2 == 0 && count == n / 2)
    {
        evenMid = root->data;
    }
    else if (n % 2 == 0 && count == (n / 2) + 1)
    {
        return (evenMid + root->data) / 2;
    }

    float rightAns = findMedianInBST(root->right, n);

    return rightAns;
}

int main()
{
    int n;
    struct node *tree = NULL;
    printf("Enter number of elements in array:");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements of array:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        tree = insertNode(tree, arr[i]);
    }
    float median = findMedianInBST(tree, n);
    printf("The Median is: %.2f", median);
}