// huadeng.c

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();



void create()
{
        set_name(HIG "����Ը����" NOR, ({"deng", "hua deng","zouma deng"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 100000);
                set("long", "һ�������Ը���ƣ������и�����ľ��� !cha cha ����\n");
        }

        set("is_monitored", 1);
        setup();
}
void init()
{
        if (!wizardp(this_player())) {
                set("no_get", "�ٺ٣����ΰ�! \n");
                set("no_give", "�ٺ٣����ΰ�! \n");
                set("no_drop","��ô�����Ļ��ƣ���������! \n");
                set("no_put",1);
                if (!(this_object()->query("owner")))
                      this_object()->set("owner",this_player()->query("id"));
        }

        add_action("do_eat", "chacha");
}
int do_eat(string arg)
{
        object victim = this_player();
        int i, level,qn, which=0,max_level=0;
        mapping skill_status;
        string *sname,*str;
        if (!id(arg))
                {tell_object(victim ,"��Ҫ��ʲô��\n");return 1;}

                if (!(this_object()->query("owner")))
        {tell_object(victim ,"��������������ٴβ���յ����Ը���ƣ�����ǵȶ���û��Ӧ��\n");return 1;}
        if (!(this_object()->query("used")) && !(victim->query("lll/deng_2005")))
        {
        victim->add("combat_exp", (int)victim->query("combat_exp") / 40);

        victim->add("daoxing",victim->query("death/dx_loss"));
        victim->save();
        if( (int)victim->query("potential") > (int)victim->query("learned_points"))
                        qn=(int)victim->query("potential")-(int)victim->query("learned_points");

        qn=qn/5;
        victim->add("potential",qn);

        skill_status = victim->query_skills();
        sname  = keys(skill_status);

        for(i = 0; i < sizeof(skill_status); i++)
           {level = skill_status[sname[i]] ;
            if(level>max_level)
              {max_level=level;
               which=i;
              }
           }
        if(max_level>100)
         {
                tell_object(victim,"��õ���������!\n");
                victim->set_skill(sname[which],max_level+2);
         }
         else if(max_level>50)
         {
                victim->set_skill(sname[which],max_level+4);
                tell_object(victim,"��õ��ļ�����!\n");
         }
              else
              {
                  tell_object(victim,"��õ���������!\n");
// 86                  victim->set_skill(sname[which],sname[which],max_level+8);
                victim->set_skill(sname[which],max_level+2);
                }
        victim->set("lll/deng_2005",1);
        this_object()->set("used",1);
        if( userp(victim) ) log_file("DENG2004", sprintf("%s(%s) Got recovered on %s.\n", victim->name(1), geteuid(victim), ctime(time()) ) );

        message_vision(HIG "\n$N����һյ�����Ը���ƣ�һ����ɫ�ľ����ܳ���Ц����ʩ�������\n"
        +"$N�õ��˵Ƶ������������\n" NOR, victim);


        return 1;
        }
        str=({"$N����Ը���ƣ�Ը���ƶ�ʱ�ֳ�$N��ª����ף�\n",
              "$N�ѵƾ�������Ը�����ֳ�����ɫ�����֮�⣡",
              "$NС�ĵİѵƲ���ţ��ƾ�Ȼû��ӳ��",
              "$N�ѵƵ�������������һ�£��������ˣ�",
              "$N�ѵ�����һ�ף����������ճ����������Ĳ�ϼ��",
              "$N���ŵƣ��Ե�˵����������ڣ�Ը���ƺ��޷�Ӧ��һ����׾֮��",
             });

         message_vision(HIC+str[random(sizeof(str))]+"\n", victim);
        return 1;

}



