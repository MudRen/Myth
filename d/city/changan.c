inherit "/std/city.c";

void create ()
{
reload("����");
set ("short", "������");
set ("long", @LONG

����һ�����ϵĳ��С�
LONG);

  set("exits", ([
  "down" : __DIR__"jiuguan1",
//14    "up" : "/d/quest/club/clubbar",
]));

//�Ӹ�qianmian guai
//by seng@2005-1-25
  set("objects", ([ /* sizeof() == 2 */ 
 "/d/changan/npc/qianmian" :1,
 ])); 

  set("no_clean_up", 1);
  set("outdoor", 1);
  setup();
}

int clean_up()
{
      return 0;
}

