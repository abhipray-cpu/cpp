/*here is the algortithm*/

// Node *Conversion(Node *head)
// {
//     Node *temp,*p,*q;
//     if(head==NULL||head->next==NULL)
//     {
//         return head;
//     }
//     temp=findMiddle(head);
//     p=head;
//     while(p->next!=temp)
//     {
//         p=p->next;
//     }
//     p->next=NULL;
//     q=temp->next;
//     temp->next=NULL;
//     temp->prev=conversion(head);
//     temp->next=Conversion(q);
//     return temp
// }