if(root==NULL)
    return;
    cout<<root->data<<" ";
    traverse1(root->first_child);
    traverse1(root->next_sibling);