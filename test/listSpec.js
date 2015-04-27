const Immutable = imports.gi.Immutable;

describe('ImmutableList', () => {
    let l;
    beforeEach(() => {
        l = new Immutable.List();
    });

    it('should be empty to begin with', () => {
        expect(l.is_empty()).toBe(true);
    });

    it('has a cons function', () => {
        l = Immutable.List.cons('foo', null);
        expect(l.is_empty()).toBe(false);
    });

    it('has a get_length method', () => {
        expect(l.get_length()).toBe(0);

        l = Immutable.List.cons('foo', null);
        expect(l.get_length()).toBe(1);

        l = Immutable.List.cons('bar', l);
        expect(l.get_length()).toBe(2);

        l = Immutable.List.cons('baz', l);
        expect(l.get_length()).toBe(3);
    });

    it('has a head method', () => {
        let cons = Immutable.List.cons;
        l = cons('foo', cons('bar', null)); 
        print(l.to_string());
        let h = l.head();
        expect(h).toBe('foo');
    });
});
