inherit "/std/city.c";

void create ()
{
 //  reload("����");
 set ("short", "����");
set ("long", @LONG

�ڹ�¡�˵ģ��㿴����������ʲô������������
LONG);
  set("exits", ([
    "up" : "/d/xueshan/xuelu",
]));
  set("no_clean_up", 1);
  set("outdoor", 1);
  setup();
}

int clean_up()
{
      return 0;
}

