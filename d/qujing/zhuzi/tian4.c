// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "������");
  set ("long", @LONG

���������Ϲ����ŵĶ��ţ�����Ʈ���ӻ������顰���Ϲ���������
���������������֣�������ͨ��ǽ�ɽ�µ�·���ſ���ЩУξ��
�̲����ˡ�

LONG);

  set("exits", ([ 
    "northeast" : "/d/qujing/qilin/polu1",
    "west" : __DIR__"tian3",
  ]));
  set("objects", ([
    __DIR__"npc/xiaowei" : 2,
  ]));
  set("outdoors", __DIR__"");
  setup();
}

int valid_leave(object who, string dir)
{
  if (! interactive(who) &&
     dir == "northeast")
    return 0;
  return ::valid_leave(who, dir);
}
