//Cracked by Roath

//  ����֮�� ������
//  by happ@YSZZ 2000.4.6
//  /d/qujing/yunzhan/shulin1.c

inherit ROOM;

void create ()
{
  set ("short", "[33m����[m");
  set ("long", @LONG

���ﾡ��Щ�����������һ�߽���������ʧ�˷���ֻ��������ֻ��
һƬī�̣���Χ��ɫ����һ���ġ�

LONG);

  set("exits", ([
        "north":__DIR__"shulin6",
        "east" : __DIR__"shulin8",
        "west" : __DIR__"shulin4",
        "south": __DIR__"shulin4",
      ]));
    set("objects",
    ([
    "/d/qujing/yunzhan/npc/pig":1,
    ]));
  setup();
}
void init()
{

        if( present("zhu guai 2") )
        {
        remove_call_out("des");
        call_out("des",1);
        }
}
void des()
{
        object pig;
        pig=find_living("zhu guai");
        destruct(pig);
}
