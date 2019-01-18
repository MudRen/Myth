//�������Ե��칬����
//fabao.c

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC"�칬����"NOR, ({ "fa bao","fabao"}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "һ���칬��СС��������ħ����������ȥ��\n");
                set("value", 0);
                set("material", "steel");
                 
         }
}

void init()
{    
        add_action("do_chuansong", "chuansong");
}

int do_chuansong(string arg)
{
        int i,exp,pot,dx,count,base_exp,add_exp;
        object ob,me,*team;
              
        me=this_player();
        ob=this_object();
        if(!arg||arg!="fa bao") 
                return notify_fail("��Ҫ����ʲô��\n");

        if(ob->query_temp("host")!= me->query("id")
        ||!me->query_condition("zzz_busy")||!me->query_temp("team_count"))
                return notify_fail("����º������û��ϵ�ɣ�\n");

        if (!present("fa bao",me) )
                return notify_fail("������û���칬������\n"); 
        //check ok
                message_vision(HIY"$NĬ�˷�����ֻ���칬������һ�Ź��������š�\n"+HIR"ֻ�����䡹��һ�����칬������ʧ�� ��\n"NOR, me);
        count=me->query_temp("team_count");
        if (count<2) count=2;   
        base_exp=1500/count;
        team=me->query_team();
        count=sizeof(team);
        //write("\n"+sprintf("%d",count));
        for(i=0;i<count;i++)
        { if(team[i]!=0)
                {
                        if (team[i]->query_condition("zzz_busy"))
                        {if(!team[i]->query("zzz_job_count"))
                         team[i]->set("zzz_job_count",1);
                         else
                         team[i]->add("zzz_job_count",1);  
                         add_exp=team[i]->query("zzz_job_count")/10;
                         exp=base_exp+random(200)+add_exp;
                         dx=exp+random(500)-random(500);
                         pot=exp/5+random(100);
                         team[i]->add("potential",pot);
                         team[i]->add("daoxing",dx);
                         team[i]->add("combat_exp",exp);
                         tell_object(team[i],HIW"�㱻�����ˣ�\n
                         " + chinese_number(exp) + "��ʵս���飡\n
                         " + chinese_number(dx) + "�ĵ��У�\n
                         " + chinese_number(pot) + "��Ǳ��\n"+
                       NOR);
                        }
                        } 
                }
                  me->delete_temp("team_count");
                  
                ob->move(get_object("/obj/empty")); 

          return 1;
}


