// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "�ڹ�");
  set ("long", @LONG

�ڹ�ׯ�����£���̴��ľ�������ܸ��������ϵ����Ͻ���Ϸ�顣��
�м�������������������ʮ�˴���з���ޱ��������Ķ�֯��ԧ��
������

LONG);
  set("exits", ([ 
    "west" : __DIR__"neiyuan",
    "southwest" : __DIR__"housan",
  ]));
  set("objects", ([
    __DIR__"npc/king" : 1,
  ]));
  setup();
}
