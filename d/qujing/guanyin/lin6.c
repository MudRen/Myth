inherit ROOM;

void create ()
{
  set ("short", "�ֵ�");
  set ("long", @LONG

����ɽ�ֽ���ɫ���������Ƿ������ޣ�����һ��������Ŀ��
�о���ԶԶ����ɽ��������¥̨ӰӰ����������
LONG);
 
  set("exits", ([
        "east"      : __DIR__"lin5",
        "west"   :  __DIR__"lin7",
      ]));
        set("objects", 
        ([ //sizeof() == 3
                __DIR__"npc/guai1" : 3,
        ]));

  set("outdoors", __DIR__);

  setup();
}

