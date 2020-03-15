var Node = {
    parent : nil,
    children : [nil],
    value: 0,

    addCh : ([children]) => {
        for ch in children {
            
            # weak reference
            ch.parent = @this;

            this.children = this.children + ch;
        }
    },

    getParentValue : () => {
        # optional deref
        return parent?.value;
    },

    getParent : () => {
        # owned deref
        return parent;
    }
};

var root = <Node>;

var ch = <Node>;
ch.value = 1;

root.addCh(ch);
