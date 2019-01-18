// cron.c
// by mudring

#pragma optimize
//#pragma save_binary

#include <ansi.h>
#include <command.h>

inherit F_DBASE;
#define CRON_DIR "/d/quest/baoshi/"

string *families = ({
  "�ڼ���", "�����", "���ù�", "Ů����",
  "����", "��ƽ��", "��ׯ��", "������",
  "�շ���", "�����", "���Ϲ�", "���ٹ�",
  "����ׯ", "���޹�",
});

nosave int LAST_HARD_DIS;
nosave int flag = 0;
int set_last_hard_dis();

void check_task();
void auto_clear();
void start_qujing();
void start_baoshi();

void create()
{
    seteuid( ROOT_UID );
    set("channel_id", "���羫��");
    CHANNEL_D->do_channel( this_object(),
        "sys", "���羫���Ѿ�������\n"NOR);
    set_heart_beat(30);
    set_last_hard_dis();
}

int clean_up() { return 1;}
int query_last_hard_dis() {   return LAST_HARD_DIS;  }
int set_last_hard_dis()
{
    LAST_HARD_DIS = time();
    return flag;
}

private void heart_beat()
{
    call_out("check_task", 1);
}

void check_task()
{
    mixed *local;
    object npc;

    local = localtime(time());
    if (!(local[1] % 10))
    {
        call_out("auto_clear",1);
        CRON_DIR "feizei.c"->choose_npc();
    }
    if (!(local[1] % 50))
    {
        CRON_DIR "choose.c"->choose_mpc();
    }
    if (!(local[1] % 79))
    {
        TASK_D->init_dynamic_quest();
        message("system",HIR"\n���·ֲ�����ʹ����������"
                + HIG" ����������ʹ���ֲ����\n" NOR, users());
    }
    if (flag == 1)
    {
        TASK_D->init_dynamic_quest(1);
        flag = 0; 
        set_last_hard_dis();
        message("system",HIR"\n���·ֲ�����ʹ����������"
                + HIG" ������ʹ���ֲ����\n" NOR,users());
        if (random(4))
            start_qujing();
    }
    if (local[1]==55 || ((int)time()-(int)query_last_hard_dis()) > 4720)
    {
        flag=1;
        message_system( HIR "����ʹ������һ���Ӻ����·ֲ�������   "NOR); 
    }
    if (!(local[1] % 65) )
    {
        start_baoshi();
    }
    if (!(local[1] % 41))
      {
        rm("/log/dlog/money");
        "/adm/daemons/ran_moneyd"->move_money();
       }
}

void auto_clear()
{
    int mem;
    object *ob;

    CHANNEL_D->do_channel( this_object(), "sys",
        sprintf("ϵͳ�Զ���� " + reclaim_objects() + " ��������"));

"/cmds/arch/cleanup.c"->main(this_object(), "/d/qujing/wuzhuang/obj/jinjizi.c");
"/cmds/arch/cleanup.c"->main(this_object(), "/d/qujing/wuzhuang/obj/danpan.c");
    ob = filter_array(objects(), (: clonep :));
    mem = sizeof(ob);
    while (mem--)
    if (!environment(ob[mem]) &&
        !interactive(ob[mem]) &&
        !ob[mem]->query_temp("body_ob") &&
        !ob[mem]->query("no_cron"))
    {
        reset_eval_cost();
//        printf("%O\n", ob[mem]);
        CHANNEL_D->do_channel(this_object(), "adm",
            sprintf("%O", ob[mem]));
        destruct(ob[mem]);
        ob -= ({ 0 });
        mem = sizeof(ob);
    }
}

void start_qujing()
{
    int k;
    object ts;

    k = random(sizeof(families));        
    ts = new(CRON_DIR "ts");
    ts->set("target", families[k]);
    ts->invocation(k);
    message_job(HIW"��������"HIG"������! ��˵��������ʦͽ�Ѿ�����"
                + families[k] + "�ˣ����Ų��þͻᵽ����ɽ�ˡ�");
}

void start_baoshi() 
{ 
    object ob;
    object newob;
             
    newob = new(CRON_DIR "baoshi");
    ob = NPC_D->task_npc(); 

    if (newob->move(ob))
    { 
        CHANNEL_D->do_channel( this_object(), "sys", 
            "��ʯ�䵽��" + ob->query("name") + "(" + ob->query("id") + ")�����ϡ�");  
        message_job(HIR"�����챦��"HIW"ͻȻ���д��˸�ը�ף�һ�������ճ���������һ�������"
                    + ob->query("place") + "�ķ�����ȥ��"); 

        if (newob->query("b_lvl") > 14)
            message_job( HIR"�����챦��" + newob->name() + "���ٷ��䣡"); 

    } else
    {
        CHANNEL_D->do_channel( this_object(), "sys", "���α�ʯ����ʧ��"); 
    }            
}

