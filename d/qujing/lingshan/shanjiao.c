//Cracked by Roath


// create by snowcat.c 12/8/1997


//note, disabled access due to qujing change...weiqi

inherit ROOM;

void create ()
{
  set ("short", "��ɽ��");
  set ("long", @LONG

ֻ��ɽ����������࣬����������ԶԶ�ɼ�ɽ����������
��ϼ�����硣��Ұ�Ǹ��ָ�����֥�ɹ���ݣ��ƺ��Ų������
��˫�ɡ�

LONG);

  set("exits", ([
        "north"   : __DIR__"dalu1",
        "westup"   : __DIR__"yang3",
      ]));
  set("objects", ([
        __DIR__"npc/jinding" : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}



