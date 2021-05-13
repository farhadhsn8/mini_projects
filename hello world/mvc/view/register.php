

<form action="index.php?c=register" method="post">
    <label>name</label>
    <input type="text"  name="frm[username]">
    <br>
    <label>lastname</label>
    <input type="text"  name="frm[lastname]">
    <br>
    <label>city</label>
    <select name="frm[city]" id="">
        <option value="1">tehran</option>
        <option value="2">esfahan</option>
        <option value="3">shiraz</option>
    </select>
    <br>
    <label>password</label>
    <input type="password"  name="frm[password]">
    <br>
    <input type="submit" name="btn">
</form>