// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "��Ժ");
  set ("long", @LONG

��Ժ��ϸʯ�������̵أ����ϽǼ�����ͩ����̨��ֲ������������
�����ƻ���������������ͨ����������������ĵ����ҩ����һ·��
���ڹ������ϴ���˪Ҷ�������������

LONG);

  set("exits", ([ /* sizeof() == 1 */
    "west" : __DIR__"zheng",
    "east" : __DIR__"nei",
    "southeast" : __DIR__"housan",
  ]));
  set("outdoors", __DIR__"");
  set("objects", ([
      __DIR__"npc/taijian" : 2,
  ]));
  setup();
}
