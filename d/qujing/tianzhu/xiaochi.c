// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "С�Ե�");
  set ("long", @LONG

������ɸɾ�����������೤�ʳ�������С�Ե���˶��Ǹ���
���ھӽַ���һ�߳���ʲô��һ��������̸�������λ��ɩ��
���ڲ������ӡ�

LONG);

  set("exits", ([
        "north"   : __DIR__"jiedao91",
      ]));
  set("objects", ([
"/obj/boss/tianzhu_fu"   : 1,
      ]));

  setup();
}


