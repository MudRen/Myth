// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "ҩ��");
  set ("long", @LONG

ҩ���ſ�̯��һЩ����ɹ�Ĳ�ҩ����������һ����Ĵ�ҩ��װ��
��ʽ��ҩ��ǽ������һ�ң����顰��Ѻ������ĸ��֡�

LONG);

  set("exits", ([ 
    "south" : __DIR__"tian1",
  ]));
  set("objects", ([
"/obj/boss/zhuzi_laotong" : 1,
  ]));
  setup();
}
