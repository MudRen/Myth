inherit "/std/city.c";

void create ()
{
reload("����");
set ("short", "������");
set ("long", @LONG

����һ�����ϵĳ��С�
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"zhuque-s1",
]));
  set("no_clean_up", 1);

  setup();
}

int clean_up()
{
      return 0;
}

