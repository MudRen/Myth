// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "��Ժ");
  set ("long", @LONG

һ���������������Ŵӱ��ߵ���Ժͨ����������м�Ƭ�˵�
����һЩ�߲ˣ��˵��Դ���һ���ϼܣ�������������͵�С��
�ϡ��ϱߵ������и��̴ѣ�ð�����̡�

LONG);

  set("exits", ([
        "north"   : __DIR__"siyuan",
        "south"   : __DIR__"zhaifang",
        "northwest"   : __DIR__"baodian",
      ]));
  set("outdoors", __DIR__);

  setup();
}


