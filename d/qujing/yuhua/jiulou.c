// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "��¥");
  set ("long", @LONG

��¥����������˶���һʮ���ţ�ʮ�ֺ�������¥�ٽֵĴ���
�����˸�ɫ�ʵ�����������ʲôϲ��Ҫ������ٰ졣��¥����
�������Ʈ��һ���������ζ��

LONG);

  set("exits", ([
        "east"   : __DIR__"xiaojie3",
      ]));
  set("objects", ([
"/obj/boss/yuhua_jiubao"  : 1,
      ]));

  setup();
}



