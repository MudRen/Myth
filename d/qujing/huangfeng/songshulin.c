// created by angell 1/1/2001
// room: /d/qujing/huangfeng/songshulin.c

inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

�ߴ������֦Ҷ��ï�������֦Ҷ�Ŀ�϶���������͸�ּ��
����������ã��ں�����Ҷ�����µ�����ߡ�ɽ�������
����ɽ��ɳɳ���죬������衣ż��һЩ�����˵�С��������
���������������˰�����

LONG);

  set("exits", ([
        "northeast": __DIR__"yangchanglu1",
      ]));
//  set("outdoors", __DIR__);
        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/animal" : 2,
        ]));

  setup();
}





