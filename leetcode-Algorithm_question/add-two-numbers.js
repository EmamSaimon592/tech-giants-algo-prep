var addTwoNumbers = function(l1, l2) {
    // initialize sum to 0, and create a new ListNode to hold the result
    let sum = 0;
    let current = new ListNode(0);
    let result = current;
    
    while(l1 || l2) {
        
      // continue to add the values of l1 and l2 to sum, and move the pointers to the next nodes
        if(l1) {
            sum += l1.val;
            l1 = l1.next;
        }
        
      // if l2 is not null, add its value to sum and move the pointer to the next node
        if(l2) {
            sum += l2.val;
            l2 = l2.next;
        }
        
        current.next = new ListNode(sum % 10);
        current = current.next;
        
        sum = sum > 9 ? 1 : 0;
    }
    
    if(sum) {
        current.next = new ListNode(sum);
    }
    
    return result.next;
};
