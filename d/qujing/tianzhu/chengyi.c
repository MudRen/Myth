// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "���µ�");
  set ("long", @LONG

���µ������������ɫ��������ȹ���·����ֶ�������������
���ػ�ɫӦ�о��С�һ���ŵش���ǰ�������Ϲҵ��ݺ��в�
�����ڴ���ѡ���ʵ��·���

LONG);

  set("exits", ([
        "south"   : __DIR__"jiedao96",
      ]));
  set("objects", ([
"/obj/boss/tianzhu_tao"   : 1,
      ]));

  setup();
}


