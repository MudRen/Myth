// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "�᷿");
  set ("long", @LONG

�᷿�ɾ����룬���ſ���һ̴��ľ̫ʦ�Σ������а��������Ա�ϯ
���磬�Ϸ����ϲ�����ű���һש̨����С¯����Ϊ���£������
�����ˡ�

LONG);

  set("exits", ([ 
    "north" : __DIR__"huitong",
  ]));
  set("objects", ([ 
    "/d/obj/food/chahu" : 1,
  ]));
  set("sleep_room",1);
  setup();
}
