inherit ROOM;

void create ()
{
  set ("short", "�ȵ�");
  set ("long", @LONG

���ȵ�����վ���������ȶ�������յ���
�ƻ�������ǰ����·��
LONG);

  set("exits", ([
        "out" : __DIR__"shanmen",
        "north" : __DIR__"langdao2",
      ])); 

  setup();
}

