var DoubleLinkedListNode = {
    value : nil,

    prev : @nil,
    next : nil,

    insertAfter : (node) => {
        node.prev = @this
        node.next = this.next
        if this.next != nil {
            this.next.prev = @node
        }
        this.next = node
    },

    delete : () => {
        if this.prev? != nil {
            this.prev!.next = this.next
        }
        if this.next != nil {
            this.next.prev = this.prev
        }
    },

    printFromThis : () => {
        print(this.value)
        if this.next != nil {
            this.next.printFromThis()
        }
    },

    printBeforeThis : () => {
        if this.prev? != nil {
            this.prev!.printBeforeThis()
        }
        print(this.value)
    }
}

var head = <DoubleLinkedListNode value = "head">
var node1 = <DoubleLinkedListNode value = "1">
var node2 = <DoubleLinkedListNode value = "2">
var node3 = <DoubleLinkedListNode value = "3">

head.insertAfter(node1)
node1.insertAfter(node2)
node2.insertAfter(node3)

head.printFromThis()

node2.printBeforeThis()
