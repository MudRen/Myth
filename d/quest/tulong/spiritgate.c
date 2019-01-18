#include <room.h>
inherit ROOM; 
#include <ansi.h>
int do_knock(string arg);
void create()
{
      set("short","����԰");
      set("long",@LONG
�㴦��һ��ֲ���軨�Ļ�԰���Ȼ�����ǿ�����ʱ�ڣ�����
��Щ���������Ĳ�������������е�������ˬ���ݴ�����ЩС����
�������௵ؽе�������
LONG);
      set("exits",([ 
            "west"  : "/u/wuyou/workroom/",
      ]));
      setup();
} 

void init()
{
        add_action("do_knock","knock");
}
int do_knock(string arg)
{ 
        object member;

        member = this_player()->query_team();
        if (!arg || arg != "spiritgate")
        {
                return notify_fail("��Ҫ��ʲô��\n");
        }
        if( this_player()->query("combat_exp")<5000000) 
                return notify_fail("�������������ǽ����˾����ġ�\n");
        if( sizeof(member) != 7 )
                return notify_fail(HIG+BLINK"������г�Ա��Ŀ��������Ϊʮ��֮�룬����֮�Ų��Ὺ����\n"NOR);
        message_vision( HIG "$N�����������۶����£�һ�������������У�$N���͵���һ������ĵط���\n" NOR, this_player());
        message("channel:chat", HBMAG"��������硿����֮�ſ�����ĳС�ӽ����˾�����磬�ƽ������ķ�ӡ!\n"NOR,users());
        this_player()->move("/d/quest/tulong/spirit1"); 
        this_player()->set("fighter",0); 
        this_player()->set("mark/diary",0); 
        this_player()->set_temp("m_success/����",0);  
        this_player()->set_temp("m_success/��Ӱ",0);  
        this_player()->set_temp("m_success/����",0);  
        this_player()->set_temp("m_success/���",0);  
        return 1;
}


