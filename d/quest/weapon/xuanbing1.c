//m_weapon .....tianjianshi.c
//xuanbing.c

#include <ansi.h> 
inherit ROOM;

void init() 
{
        add_action("do_change_id", "change_id");
       
        seteuid(getuid()); 
}

void create()
{
        set("short", "�����Ŷ�");
        set("long",
                "�����������Ŷ������涴��֮�Ͻ�����ʯӢ����״�ᾧ�壬�Ե�\n"
                "ʮ��Ư����ǰ��һ���޴��¯��ǰվ��һλ��������������¯������\n"
                "ʲô���£��Ա߼������δ��������Ŵ�ͷ�ô���һ���ƺ���Ҳ�ղ�\n"
                "���ʲô�������Ա���ϸ�ķ��ż��Ѹոճ�¯�ı��������ֺ��˵�ɱ\n"
                "�����Ǵ���Щ������ɢ�������ġ�\n"

        );
        set("exits", ([
                "out" : __DIR__"xuanbing",
        ]));
        set("objects" , ([
               __DIR__"npc/tianjianshi" : 1,

             ]) );
        setup();
//        replace_program(ROOM);
}

//added by wuyou

int  do_change_id(string arg) 
{ 
       int i;
       string w_id, new_id, w_name; 
       object me=this_player(); 
       
       if (!me->query("weapon/make"))
          return notify_fail("������û������������\n");

       w_name=me->query("weapon/name");
       w_id=me->query("weapon/id");

       if( !arg || arg == "")  
           return notify_fail("���� change_id <��Ӣ����> ��������\n"); 
           
       if( sscanf(arg, "%s", new_id) != 1) 
           return notify_fail("���� change_id <��Ӣ����> ��������\n"); 
             
        i = strlen(new_id);
        while(i--)
                if( new_id[i]<'a' || new_id[i]>'z' )
                        return notify_fail("�Բ��𣬱�����Ӣ�Ĵ���ֻ����Ӣ����ĸ��\n");

        me->set("weapon/id", new_id);
        me->start_busy(3);
        me->receive_damage("kee", 500);
        me->receive_damage("sen", 500);
                  
        write(""+w_name+"��Ӣ�����ƸĶ��ɹ���\n"); 
        return 1; 
} 
     

