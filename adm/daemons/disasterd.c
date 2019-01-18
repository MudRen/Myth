// disasterd.c
// rewritten by mudring
 
#include <ansi.h> 
inherit F_DBASE; 

#define HAOJIE_DIR "/d/quest/haojie/"
 
string *factions=({ 
    "����ɽ", "���ƶ�", "��ɽ����", "��ׯ��", 
    "��ѩɽ", "�Ϻ�����ɽ", "�¹�", "���޵ظ�", 
    "��������", "�ݿ�ɽ�޵׶�", "��˿��", 
    "����ɽ���Ƕ�", "������", "��ԯ��Ĺ", 
}); 
string faction;
int count; 

void create() 
{ 
    seteuid(getuid()); 
    remove_call_out("disaster"); 
    call_out("disaster",30,0);    
} 

void announce(string str)
{
    message("system", HIR"����ؽ١�"HIW + str + "\n"NOR, users()); 
}

void disaster(int count) 
{ 
    if (count == 0)
    { 
        announce("̫�׽��ǣ����������̫���ˣ���ʹ��ħ������"); 
        announce("̫�׽��ǣ�������ؼ�һ���ƽ��������⣡"); 
    }        
    faction = factions[count]; 
    announce("ħ�̵ĵ�" + chinese_number(count+1) + "��Ŀ����Ѫϴ��"HIR + faction + HIW"����"); 
    call_out("copy_npc", 11, count); 
} 

int filter_user(object ob)
{
    if (!ob || wizardp(ob))
        return 0; 

    if (ob->query("family/family_name") != faction)
        return 0;

    if (ob->query("combat_exp") < 30000)
        return 0;

    return 1;
}
 
void copy_npc(int count) 
{ 
    object ob, *user; 
    object site; 
    string leader;
    int i, j; 
    int t = 0; 

    leader = STATU_D->family_master(faction);
    site = STATU_D->family_place(faction);

    user = filter_array(users(), (: filter_user :));
    j = sizeof(user); 

    for (i = 0; i < j; i++)
    { 
reset_eval_cost();
        ob = new(HAOJIE_DIR + "yg-" + STATU_D->family_id(faction));
        ob->copy_status(ob, user[i]); 
        ob->move(site); 
        tell_object(user[i], HIY"" + leader + "������:ħ�����Ʊ���,�ٻر�����ս��\n"); 
        message_vision("$N�����ɷ�����˹�����\n", ob); 
        t++; 
    } 

    if (t == 0)
    { 
        if (count < 13)
        { 
            announce("����" + faction + "���¿���һ�ˣ�ħ�̲�ս��ʤ��һ��������" 
                     + faction + "��"); 
            announce("ħ�̽�����ħ�����Ц����û�뵽������׵��֣�����������Ҳ��������������"
                     "��һ����"); 
            call_out("disaster",11,count+1); 
        } else
        { 
            announce("��Ȼ���ɷ���ɱ�У�����ħ�̣�������ʧ̫��һʱ���ȷ�Ѫ�꣬����һƬ�찵��"); 
            announce("̫�׽��ǣ�ħ����Ȼ��ʱ���ˣ�����֪ʲôʱ���ֻ����������"); 
            call_out("disaster",3600,0); 
            call_out("juedou",5); 
        } 
    } else
    { 
        call_out("verdict_time", 600, t, count); 
    } 
} 

void verdict_time(int t, int count) 
{ 
    object *user; 
    int i, j, exp; 

    if (DISASTER_D->query("xinmo_die") < t)
    { 
        user = filter_array(users(), (: filter_user :));
        j = sizeof(user); 
        for (i = 0; i < j; i++) 
        { 
            exp = (int)user[i]->query("daoxing") / 100; 
            if (exp > 1000) exp = 1000; 
            user[i]->add("daoxing", -exp); 
            tell_object(user[i], HIC"ħ��Ѫϴ" + faction
                + "����,�㻤��������ʧȥ��" + chinese_daoxing(exp) + "���У�\n"); 
        } 
        announce(faction + "������ս֮�£��������أ��Ӵ������伣��"); 
    } else
    { 
        announce(faction+"������ս֮�£�������ħ�̣��������ⳡ�ƽ١�"); 
    } 
    DISASTER_D->delete("xinmo_die"); 
    if (count < 13) 
    { 
        announce("ħ�̽�����ħ�������һ������һ����"); 
        call_out("disaster", 11, count + 1); 
    } else
    { 
        announce("��Ȼ���ɷ���ɱ�У�����ħ�̣�������ʧ̫��һʱ���ȷ�Ѫ�꣬����һƬ�찵��"); 
        announce("̫�׽��ǣ�ħ����Ȼ��ʱ���ˣ�����֪ʲôʱ���ֻ����������"); 
        call_out("disaster", 3600, 0); 
    } 
} 

