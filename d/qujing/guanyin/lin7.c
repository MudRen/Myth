inherit ROOM;

void create ()
{
  set ("short", "�ֵ�");
  set ("long", @LONG

����ɽ�ֽ���ɫ���������Ƿ������ޣ�����һ��������Ŀ��
�о���ԶԶ����ɽ��������¥̨ӰӰ����������
LONG);
 
 set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/guai" : 2,
        ]));
  set("exits", ([
        "east"      : __DIR__"lin6",
        "westup"   :  __DIR__"shanmen",
          "northwest" : __DIR__"shandao1",
        "south" : __DIR__"lin8",
      ]));

  set("outdoors", __DIR__);

  setup();
}

