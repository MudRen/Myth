// 兰陵续 by Calvin

inherit ROOM;

void create ()
{
        set ("short", "回春诊所");
        set ("long", @LONG

这是一家高级的诊所,诊所的老板也是诊所的最有名的郎中,老板出生官宦世家,从
小就饱读了各种名医书籍,并在很年轻时就著下自己的语论,有了自己的独到之处。
所以一般的小毛小病均不在他的话下。你可以使用(cure)尝试医治。

LONG);

        set("exits", 
        ([ //sizeof() == 4
          "east": "/d/calvin/lanling/jie2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
          "/d/calvin/npc/yishi" : 1,
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
