// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "��¥");
  set ("long", @LONG

��¥������һ�����ܸߺ�С�Ĵ��ӣ�����ƻ�ͨ����������ϯ����
��������ζ�سԷ��������������罫�������ӷֳ����׼�����ͬ��
����ϯλ��������Ϧ�ֽ֡�

LONG);

  set("exits", ([ 
    "north" : __DIR__"xi2",
  ]));
  set("objects", ([
"/obj/boss/zhuzi_wan" : 1,
  ]));
  setup();
}
