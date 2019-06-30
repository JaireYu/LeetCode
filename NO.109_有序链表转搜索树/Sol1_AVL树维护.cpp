/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//指针初始化时一定要赋值NULL，以防野指针
#define LH +1
#define EH 0
#define RH -1
typedef struct AVLtree{
    int val = 0;
    int bf = 0;
    AVLtree *left = NULL;
    AVLtree *right = NULL;
}AVLtree;
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode * p = head;
        if(p == NULL)
            return NULL;
        AVLtree* root = NULL;
        bool taller = false;
        while(p != NULL){
            AVLinsert(root, p->val, taller);
            p = p->next;
        }
        TreeNode* T;
        copy(T, root);
        return T;
    }
    void AVLinsert(AVLtree*&T, int e, bool &taller){
        if(T == NULL){
            T = new AVLtree;
            T->left = T->right = NULL;
            T->val = e;
            T->bf = EH;
            taller = true;
        }
        else{
            if(e < (T->val)){
                AVLinsert(T->left, e, taller);
                if(taller){
                    switch(T->bf){
                        case LH:
                            LeftBalance(T); taller = false; break;
                        case EH:
                            T->bf = LH; taller = true;break;
                        case RH:
                            T->bf = EH; taller = false;break;
                    }
                }
            }
            else{
                AVLinsert(T->right, e, taller);
                if(taller){
                    switch(T->bf){
                        case LH:
                            T->bf = EH; taller = false;break;
                        case EH:
                            T->bf = RH; taller = true;break;
                        case RH:
                            RightBalance(T); taller = false;break;
                    }
                }
            }
        }
        return;
    }
    void LeftBalance(AVLtree* &T){
        AVLtree* lc= T->left;
        switch(lc->bf){
            case LH:
                T->bf = lc->bf = EH;
                R_Rotate(T);break;
            case RH:
                AVLtree* rd = lc->right;
                switch(rd->bf){
                    case LH: T->bf = RH; lc->bf = EH;break;
                    case EH: T->bf = lc->bf = EH;break;
                    case RH: lc->bf = LH; T->bf = EH;
                }
                rd->bf = EH;
                L_Rotate(T->left);
                R_Rotate(T);
        }
    }
    void RightBalance(AVLtree* &T){
        AVLtree* rc= T->right;
        switch(rc->bf){
            case RH:
                T->bf = rc->bf = EH;
                L_Rotate(T);break;
            case LH:
                AVLtree* ld = rc->left;
                switch(ld->bf){
                    case LH: T->bf = EH; rc->bf = RH;break;
                    case EH: T->bf = rc->bf = EH;break;
                    case RH: rc->bf = EH; T->bf = LH;
                }
                ld->bf = EH;
                R_Rotate(T->right);
                L_Rotate(T);
        }
    }
    void R_Rotate(AVLtree *& T){
        AVLtree* lc = T->left;
        T->left = lc->right;
        lc->right = T;
        T = lc;
    }
    void L_Rotate(AVLtree *&T){
        AVLtree* rc = T->right;
        T->right = rc->left;
        rc->left =T;
        T = rc;
    }
    void copy(TreeNode *&T, AVLtree* &root){
        if(root == NULL){
            T = NULL;
            return;
        }
        T = new TreeNode(1);
        T->val = root->val;
        copy(T->left, root->left);
        copy(T->right, root->right);
        return;
    }
};