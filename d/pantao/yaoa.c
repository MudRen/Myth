// created by snowcat.c 5/23/1997
// room: /d/pantao/yaoa.c

inherit ROOM;

void create ()
{
  set ("short", "��������");
  set ("long", @LONG

�������Ȱ���֥����ޥ�������滨���ɼ������ڴ˱����ɹ���
�ȡ��������������ڽ����鵯�������Ʒʡ��м乩����ö����
���۰����̵���ҡ�

LONG);

  set("exits", ([
        "east"  : __DIR__"yaob",
      ]));

  setup();
}

