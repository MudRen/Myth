inherit ROOM;

void create ()
{
  set ("short", "�ȵ�");
  set ("long", @LONG

���ȵ�����վ���������ȶ�������յ���
�ƻ�������ǰ����·��
LONG);

  set("exits", ([
          "south" : __DIR__"langdao1",
        "north" : __DIR__"langdao3",
      ])); 

  setup();
}

