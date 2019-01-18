//Edited by wuyou@sk_sjsh 2003-4-21

inherit NPC;
#include <ansi.h>
#define CRON_DIR "/d/quest/baoshi/baoshi.c" 

void create()
{
        set_name("������", ({"wu zetian", "wu"}));
        set("long", "һ��Ů�������죬����һ��Ů���������߸����ϣ������Ϻ���ѷɫ��\n");
        set("title", HIY"һ��Ů��"NOR);
        set("gender", "Ů��");
        set("rank_info/respect", "����");
        set("age", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("per", 40);
        set("int", 40);
        set("max_kee", 700);
        set("max_gin", 700);
        set("max_sen", 700);
        set("force", 800);
        set("max_force", 800);
        set("force_factor", 50);
        set("max_mana", 800);
        set("mana", 800);
        set("mana_factor", 40);
        set("combat_exp", 220000);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("spells", 50);
        set_skill("force", 50);
        set_skill("seashentong", 50);
        set_skill("dragonforce", 50);
        set_skill("dragonstep", 50);
        set_skill("dragonfight", 50);
        map_skill("unarmed", "dragonfight");
        map_skill("dodge", "dragonstep");
        map_skill("force", "dragonforce");
        map_skill("spells", "seashentong");
        set_weight(5000000);  
        setup();
        carry_object("/d/obj/cloth/mangpao")->wear();
  
}

void init ()
{      
        object who=this_player();
        if(!who) return;

        call_out ("test_player",1,this_player());
        if ((int)who->query("quest/colors")){
        who->start_busy(2);
        }

}

string *strs = ({
  "$N��$n��̾����",
  "$N��$n���͵���",
  "$N΢Ц�Ŷ�$n˵����",
  "$N����ض�$n˵����",
});

void test_player (object who)
{
        object me = this_object();
        object where = environment (me);
       object newob; 
          int level;
        string str;
        int count, times, color;
        int i, j, k;
        mapping colors;

        colors=who->query("quest/colors");
        color=sizeof(colors);
        if (who->query("quest/colors")) 
        {  
                message_vision ("\nһ����$N����ӿ�𵭵���"+
                (color>2?chinese_number(color)+"��":"")+
                "���ơ�\n",who);
        }
        if(color == 7) { 
     
        message_vision (strs[random(sizeof(strs))]+RANK_D->query_respect(who)+
                  "�߲��������ƣ������������޹�Ȼ�����������㣡\n",me,who);
        message_vision ("\n$N����ǰ���Ͻ���$n�ĵ�ǰ������¡�\n",who,me);
        who->start_busy (3);
        times = (int)who->query("quest/number");
        if (times > 10000) times = 10000;
        count = times % 30;  
        i = 2500 + times*5/2 + 250 * (count + 1);
//        i = 2500 + times*5/2 + 200 * (count + 1);
        j = i + random(2000) - random(2000);
        k = i/5;
        who->add("daoxing", j);
        who->add("combat_exp", i);
        who->add("potential", k);
        who->add("balance", 30*i+25*j);
        who->add("weiwang", 10);
        who->delete("quest/colors");
    newob = new(CRON_DIR);
    if (newob->query("b_lvl") > 7) 
{
    level=random(7)+1;
     CRON_DIR->changename(newob,level);
   }
    newob->move(who); 
   message("channel:rumor",HIY"��"+HIR" ������ "NOR+HIY"����"+who->query("name")+"��ֲ�и���ԣ��߲��������ƣ�����ּ����"+chinese_daoxing(j)+"�ĵ��У�"+chinese_number(i)+"����ѧ��
"+chinese_number(k)+"��Ǳ�ܣ�"+MONEY_D->money_str(30*i+25*j)+"�Ľ���,������һ��" + newob->name() + "\n"NOR, users() ); 

        call_out ("reward_player",2,me,who);
        }
}

void reward_player (object me, object who)
{

  message_vision ("\n$N��æ����һ�ݣ�С�������վ������\n",who,me);

}

