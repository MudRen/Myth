// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "�ӻ���");
  set ("long", @LONG

�ӻ������治�󣬿�ǽ����һ�ų����Ļ��ܣ�������Ÿ�ʽ������
���Ϲ��ӻ��������һλ�����ӣ��Ա����ŵģ��������������
�����д�ɹ��̫����

LONG);

  set("exits", ([ 
    "north" : __DIR__"xi4",
  ]));
  set("objects", ([ 
"/obj/boss/zhuzi_pang" : 1,
    __DIR__"npc/shou" : 1,
  ]));
  setup();
}
