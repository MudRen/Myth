// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "�ܶ�");
  set ("long", @LONG

������߼�Ϊ΢��������ǿ�ؿ�����������ԼԼ��һЩ������
ȴ�ֿ��ò���ʮ��������㲻������������Ŷ��ڣ�С�ĵ���
�����ж���

LONG);

  set("exits", ([
        "down" : __DIR__"houdong",
      ]));
  set("objects", ([
        __DIR__"obj/bang"  : 1,
      ]));
  set ("sleep_room",1);

  setup();
}



