//sgzl

#include <room.h>
inherit ROOM;

int getflag;

void create()
{
set("short", "ʯ��");
set("long", @LONG
    
һ������ʯ����������ʯ�ѡ�ʯ�ʯ�롢ʯ�衢ʯ����
ʯ�ʣ����ּҵ�����һ���������İ���֮�������м����
һ�˴���(flag)�����滹��һ��ʯ��(bed)��
LONG );

set("item_desc",(["flag":"
һ��ӭ����չ����ɫ���죬�ڿտ�֮��ӭ�����(wave)����һ��ɷ�Ǻÿ������ƺ����Ѱ�(ba)����\n",

   "bed": "һ��ʯ��(gosleep,gobed,bed)�� \n", 
]));

set("exits", ([
"west"   : __DIR__"tiebanqiao",
"east"  : __DIR__"dongnei",
]));



set("objects", ([
//__DIR__"obj/flag" : 1,
]));

create_door("west", "ʯ��", "east", DOOR_CLOSED);

setup();
}

void init()
{
   object ob = this_player();
   object houzi;
   object where = this_object();

   getflag=0;

      if(this_player()->query("dntg/huaguo")=="allow")
        {
         message_vision("һȺ���Ӹ���$N�ı����������˹�����\n",this_player());
         if (! present ("hou zi 3", where))
           {
            houzi = new (__DIR__"npc/hou1");
            houzi->move(where);
            houzi->move(where);
           }
        }
   add_action("do_bed", "gosleep");
   add_action("do_bed", "gobed" );
   add_action("do_bed", "bed");

   add_action("do_ba", "ba");
}


int do_bed()
{       object me;
        me=this_player();
        message_vision("$N��ʯ����һ�ɣ�׼��˯���ˡ�\n\n", me);
        me->move(__DIR__"shichuang");
            message_vision("\n$N�굽�˱����\n", me);
                return 1;
}


int do_ba(string arg)
{
        object me;
        object qi;

        me = this_player();
        if ( !arg || ( arg != "flag" ) ) 
            return notify_fail("��Ҫ��ʲô��\n");
      if (present("flag",me)) return notify_fail("�㲻���Ѿ�����������\n");
        else if(getflag==1)  
            return notify_fail("�����Ѿ������˰����ˣ�����ֻ����һ����ˡ�\n");
        else if(me->query("dntg/huaguo")=="done")  
            return notify_fail("�����մ��죬���������Լ������ڴ˳����Ŀ���ʱ�⡣\n");
        else if ( random(10) < 5 )
          {
          if (me->query("kee")>200)  me->add("kee",-200); 
          else
            {
            me->unconcious();
            return 1;
            }
          message_vision("$Nʹ�����̵�����Ҳû������γ�����\n", me);
          }

          else
            { 
            if (me->query("kee")>200)  me->add("kee",-200); 
            else
              {
              me->unconcious();
              return 1;
              }
            qi = new (__DIR__"obj/flag");
            qi->move(me);
            message_vision("$N���һ�������������������\n", me);
            getflag=1;
            }
          return 1;
}

int valid_leave(object me, string dir)
{
 
   object ma;

   me=this_player();

   if (dir == "east" ) 
     {

        {
        if(me->query("dntg/huaguo")!="allow")
        return notify_fail("��ֻС�����ܹ������㺰��������������ѡ������û�±������ҡ���\nС�����ּ��Ҵҵ����ˡ�\n");
        }



                return ::valid_leave(me,dir);
        }
        return ::valid_leave(me,dir);



}

