// created by snowcat.c 4/4/1997
// room: /d/nuerguo/sanchalu.c

inherit ROOM;

void create ()
{
  set ("short", "����·��");
  set ("long", @LONG

����������Ů���ؽ硣����������ԼԼ�ɼ�һ�����򡣶���
�ɴ���ĸ�ӱߡ�������ȥ����һ���д��Сɽ��
LONG);

  set("exits", ([
        "northwest" : __DIR__"townc3",
        "east"      : __DIR__"westriver",
        "south"     : __DIR__"jieyang",
      ]));
  set("outdoors", __DIR__"");

  setup();
}

int valid_leave (object me, string dir)
{
  if ((string)me->query("id")=="woman" &&
      (dir=="east" || dir=="south")) 
    return 0;
  return 1;
}




