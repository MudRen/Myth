// created by angell 1/1/2001
// room: /d/qujing/huangfeng/dong4.c


inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

���ڹ��߻谵�����������ȳ��˱ǡ���������������ߴ�
����ȥ������û����ע���㣬���ǿ�Щ�뿪�ɡ�

LONG);

  set("exits", ([
        "southeast" : __DIR__"ting",
        "west" : __DIR__"dong5",
      ]));

  set("objects", ([
    __DIR__"npc/yao" : 3,
  ])); 
      
  setup();
}
