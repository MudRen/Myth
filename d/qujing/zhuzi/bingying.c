// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "��Ӫ");
  set ("long", @LONG

������һ����Ժ��פ���Żʼҵı�������Ӫ�ſ������Ʈ���λУ
ξ�����ػص��߶���һЩʿ���ڼ����ź��Ų�����Ժ�����Ͻ���һ��
���ܡ�


LONG);
  set("exits", ([ 
    "west" : __DIR__"zhuzi5",
  ]));
  set("objects", ([
    __DIR__"npc/xiaowei" : 3,
  ]));
  set("outdoors", __DIR__"");
  setup();
}
