// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "��¯��");
  set ("long", @LONG

���������һ����ʯ�������ú���һ����ͭ����������������ʯ
���Ϸ��Ÿ�ɫ���ˣ��ְ������¹��֮���Ұζ������������ͨ��
˧����������ͨ��ƫ����

LONG);

  set("exits", ([ 
    "northwest" : __DIR__"shuaifu",
    "east" : __DIR__"piangong",
    "southeast" : __DIR__"dongnei",
  ]));
  set("objects", ([
    __DIR__"obj/rou" : 5,
    __DIR__"npc/nanyao" : 2,
  ]));
  setup();
}
