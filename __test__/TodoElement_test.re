open Jest;

open TodoElement;

let () =
  describe("desc_contain_str test", () => {
    test(
      "should return false if second param is not contained in first one", () =>
      ExpectJs.expect(desc_contain_str("my string", "abc"))
      |> ExpectJs.toEqual(false)
    );
    test(
      "should return false if first param is contained in second one but is not the same",
      () =>
      ExpectJs.expect(desc_contain_str("abc", "z_abc_z"))
      |> ExpectJs.toEqual(false)
    );
    test("should return true if first param and second is the same", () =>
      ExpectJs.expect(desc_contain_str("abc", "abc"))
      |> ExpectJs.toEqual(true)
    );
    test(
      "should return true if second param is contained in first one (0)", () =>
      ExpectJs.expect(desc_contain_str("abc", "a"))
      |> ExpectJs.toEqual(true)
    );
    test(
      "should return true if second param is contained in first one (1)", () =>
      ExpectJs.expect(desc_contain_str("abc", "b"))
      |> ExpectJs.toEqual(true)
    );
    test(
      "should return true if second param is contained in first one (2)", () =>
      ExpectJs.expect(desc_contain_str("abc", "c"))
      |> ExpectJs.toEqual(true)
    );
  });
