//Cracked by Roath

//  ����֮�� ������
//  by happ@YSZZ 2000.4.14


inherit ROOM;

void create ()
{
  string woman;
  set ("short", "ɽ��");
  set ("long", @LONG

����ɽ���ϣ�����ô�ɽ��һ�������ƵĶ����㣬��ɽ��������һ��
��һЩũ�˿��Ѻõ��������������������Ź���һ��ĺ���ͨ��
ׯ�ڣ���Щ���л���Щũ������æ���š�

LONG);

  set("exits", ([
        "westup"     : __DIR__"shanpo2",
        "northeast"     : __DIR__"shanlu10",
      ]));
  switch (random(3))
        {
    case 0 :
        set("objects",([
        __DIR__"npc/furen1" :2,
        __DIR__"npc/furen2" :1,
        __DIR__"npc/furen0" :1,
                        ]));
        break;
     case 1 :
           set("objects",([
        __DIR__"npc/furen1" :1,
        __DIR__"npc/furen0" :1,
        __DIR__"npc/furen2" :2,
                        ]));
        break;
        case 2:
   set("objects",([
        __DIR__"npc/furen2" :2,
        __DIR__"npc/furen1" :1,
        __DIR__"npc/furen0" :1,
                        ]));
        break;
        }
  set("outdoors",1);
setup();
}
