const Immutable = imports.gi.Immutable;

const cons = Immutable.List.cons;

describe('ImmutableList', () => {
    let l;
    beforeEach(() => {
        l = new Immutable.List();
    });

    it('should be empty to begin with', () => {
        expect(l.is_empty()).toBe(true);
    });

    it('has a cons function', () => {
        l = cons('foo', null);
        expect(l.is_empty()).toBe(false);
    });

    it('has a to_string method', () => {
        expect(l.to_string()).toBe('()');

        l = cons('foo', null);
        expect(l.to_string()).toBe('("foo")');

        l = cons('bar', l);
        expect(l.to_string()).toBe('("bar" ("foo"))');

        l = cons('baz', l);
        expect(l.to_string()).toBe('("baz" ("bar" ("foo")))');
    });

    it('has a get_length method', () => {
        expect(l.get_length()).toBe(0);

        l = cons('foo', null);
        expect(l.get_length()).toBe(1);

        l = cons('bar', l);
        expect(l.get_length()).toBe(2);

        l = cons('baz', l);
        expect(l.get_length()).toBe(3);
    });

    it('has a head method', () => {
        l = cons('foo', cons('bar', null)); 
        expect(l.head()).toBe('foo');

        let empty = new Immutable.List();
        expect(empty.head()).toBe(null);
    });

    it('has a tail method', () => {
        expect(l.tail()).toBe(null);

        l = cons('foo', null)
        expect(l.tail()).toBe(null);

        l = cons('bar', l);
        expect(l.tail().get_length()).toBe(1);
        expect(l.tail().to_string()).toBe('("foo")');
    });

    it('has an append method', () => {
        let xs = cons('1', cons('2', cons('3', null)));
        let ys = cons('4', cons('5', null));

        expect(xs.append(ys).to_string()).toBe('("1" ("2" ("3" ("4" ("5")))))');
        expect(ys.append(xs).to_string()).toBe('("4" ("5" ("1" ("2" ("3")))))');
    });

    // TODO once lists can contain lists
    xit('has a suffixes method', () => {
        // Exercise 2.1
        let s = cons('1', cons('2', cons('3', cons('4', null))));
        // s.suffixes() == [[1,2,3,4], [2,3,4], [3,4], [4], []]
    });
});
