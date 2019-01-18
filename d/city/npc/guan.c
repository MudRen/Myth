// guangong.c �ع�
#include <ansi.h>

inherit NPC;

string jiebai();
string unjiebai();

void create()
{
        set_name(HIR"�ع�"NOR, ({ "guan gong","guan" }) );
        set("title", HIG"����ͤ��" HIW"  ���崺��"NOR);
        set("gender", "����" );
        set("age", 44);
        set("str", 50);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
        set("per", 30);
        set("long",
                "����������������ܸ����壬ǧ����ɩ�������ն�����Ĺض�ү!\n");
        set("max_force", 15000);
        set("force", 15000);
        set("force_factor", 120);
        set("combat_exp", 10000000);
        set("attitude", "friendly");
        set("inquiry", ([
                "���" : "�ǰ�... ����Ϳ��Խ��",
        ]) );
        set("max_kee", 1800);
        set("max_sen", 1800);
        set_skill("parry", 180);
        set_skill("dodge", 180);
        set_skill("force", 180);
        set_skill("literate", 120);
        set_temp("apply/attack",200);
        set_temp("apply/defense",200);
        set_skill("dodge", 200);
        set_skill("unarmed", 300);
        setup();
        carry_object("/d/obj/armor/jinjia")->wear();

        
}

void init()
{
        object ob;

        ::init();
        add_action("do_jiebai", "jiebai");
        add_action("do_unjiebai", "duanpao");
}

int do_jiebai(string arg) {
        object obj, me;
        object ob;
        int i;
        string myclass,otherclass;
        me = this_player();
        if( me->query("jiebai"))        
                        return notify_fail(
                "���Ѿ��������ֵ��ˡ�\n");
 
        if(!arg || !objectp(obj = present(arg, environment(me)))
                )
                return notify_fail("�����˭������壿\n");

        if( obj->query("jiebai"))
               return notify_fail(
                "��������Ѿ��������ֵ��ˡ�\n");
                        
        if( !living(obj) )
                return notify_fail(obj->name() + 
                "�Ѿ��޷������������ˡ�\n"); 

        if(obj==me)     return notify_fail("����Ц\n");
        if(!userp(obj)) return notify_fail("��ֻ�ɺ���Ҵ�����壮\n");


//          if ( (((int)me->query("age")<17)&&
//                  ((string)me->query("gender")=="����")) ||
//               (((int)me->query("age")<16) &&
//                 ((string)me->query("gender")=="Ů��")) )
//                   return notify_fail("��̫С�����ȳ����������˵��\n");  

        if( userp(obj) && !obj->query_temp(me->query("id") + "j"))
        {
                message_vision(MAG "\n$N��������ض�ү˵����" 
                    + RANK_D->query_self(me) 
                    + me->name() + "��Ը���"
                    + RANK_D->query_respect(obj) + 
                "�и�ͬ������ͬ������Ϊ����֮����\n\n"NOR, me,obj);           
                 me->set_temp(obj->query("id") + "j",1);
           tell_object(obj, MAG "�����Ը��ͶԷ���Ϊ����֮��������Ҳ��" 
                        +me->name() + "("+(string)me->query("id")+
                        ")"+ "��һ�� jiebai ָ�\n" NOR);
                write(MAG  
                        "����Է����ʾ��...\n" NOR);
                return 1;
        }
        
        me->set("jiebai",obj->query("id"));
        obj->set("jiebai",me->query("id"));
        
        message_vision(MAG " $N �� $n ����Ըͬ��ͬ��ͬ����������ͬ��ͬ��ͬ��������Ϊ����֮����\n" NOR,
        obj, me);
        CHANNEL_D->do_channel(this_object(), "chat",
        sprintf( "%s �� %s ��Ϊ����֮��! \n", 
        me->name(1), obj->name(1)));


        return 1;
}

int do_unjiebai(string arg)
{
        object jiebai_card1,jiebai_card2,  me;
        object jiebai_ob;
        int i, have_jiebai;
        string target, tmpstr1, tmpstr2,str1,str2;
        string cardname;
             
        me = this_player();       
        if (!me->query("jiebai"))
                return notify_fail("��û�аݰ��ӡ�\n");
        
        target = (string) me->query("jiebai");        

         if(!objectp(jiebai_ob = present(target, environment(me)))
                 )
                return notify_fail("�������֮�����ڲ��ڳ�.\n");


        if( userp(jiebai_ob) && !jiebai_ob->query_temp(me->query("id")+"d"))
                {
                message_vision(MAG "\n$N����$n˵����" 
                        + RANK_D->query_self(me) 
                        + me->name() + "����Ҫ������۾���!��ô��?\n\n"
                        NOR, me, jiebai_ob);           
                 me->set_temp(jiebai_ob->query("id")+"d",1);
           tell_object(jiebai_ob, MAG "�����Ը����۾��壬����Ҳ"
                + "��һ�� duanpao ָ�\n" NOR);
                write(MAG  
                "������ֻ�е���" +jiebai_ob->query("name")+"ͬ����...\n" NOR);
                return 1;
        }

        
        message_vision(MAG " $N �� $n �����ڿ�ʼ���۾���,�������!\n" NOR,
        jiebai_ob, me);
        CHANNEL_D->do_channel(this_object(), "chat",
        sprintf( "%s �� %s �����ڿ�ʼ���۾���,�������!������������ \n", 
        me->name(1), jiebai_ob->name(1)));
        me->set("jiebai",0);
        jiebai_ob->set("jiebai",0);
        me->add("duanpao",1);
        jiebai_ob->add("duanpao",1);
        return 1;
}
