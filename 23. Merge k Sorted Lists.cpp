// ***
//
// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
// 
// Example:
// 
// Input:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// Output: 1->1->2->3->4->4->5->6
//
// ***
//
ListNode* mergeKLists(vector<ListNode*>& lists)
{
	// Want the smallest element to have the highest priority
	// (Smaller elements are to the right of the pq), therefore, return l1->val > l2->val.
	auto compare = [](const ListNode* l1, const ListNode* l2){ return l1->val > l2->val; };

	priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> pq(compare);

	for (ListNode* head : lists)
	{
		if (head)
		{
			pq.push(head);
		}
	}
	
	ListNode dummy(0);
	ListNode* current = &dummy;

	while (!pq.empty())
	{
		ListNode* node = pq.top(); pq.pop();	

		if (node->next)
		{
			pq.push(node->next);
		}

		current->next = node;
		current = current->next;
	}

	return dummy.next;
}