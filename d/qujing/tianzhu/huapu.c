// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

������һ�������˱ǣ��ؽֵ��ſ�����һЩ�ʻ���������ǽͷ
����������ɫ�ĸɻ��ݣ���̨���������Ư���Ļ�ƿ��ƿ�ڲ�
�Ÿ�ʽ�������ʻ���

LONG);

  set("exits", ([
        "south"   : __DIR__"jiedao13",
      ]));
  set("objects", ([
"/obj/boss/tianzhu_dai"   : 1,
      ]));

  setup();
}


