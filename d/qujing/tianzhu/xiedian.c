// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "Ь��");
  set ("long", @LONG

һ����������һ�Ź�̨��̨�����Ǹ��ָ�����Ьѥ��������
���еͣ�����ƤѥҲ����Ь������ʮ����¡����̨ǰ����һЩ
�����Է���˿���Ь��

LONG);

  set("exits", ([
        "east"   : __DIR__"jiedao78",
      ]));
  set("objects", ([
"/obj/boss/tianzhu_ji"   : 1,
      ]));

  setup();
}


