// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

���ſڷ���һЩ��õ������������Ϲ���һ������ӭ������ţ�
�������治С����������������Ʒ����ǽ��һ��̨������Ҳ��
�����ڳ��۵�����Ʒ��

LONG);

  set("exits", ([
        "south"   : __DIR__"jiedao16",
      ]));
  set("objects", ([
"/obj/boss/tianzhu_shi"   : 1,
      ]));

  setup();
}


