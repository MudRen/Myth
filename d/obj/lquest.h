#include "/d/obj/longquest.h"

int give_quest(object who);
int fuming(object who);

int give_quest(object who)
{
    string *questlst;
    int i,j,k;
    
    questlst=longquest[random(sizeof(longquest))];
    i=(sizeof(questlst)-3)/5;
    who->set("longquest/name",questlst[1]);
    who->set("longquest/count",i);
    who->set("longquest/index",0);
    who->set("longquest/reward",questlst[0]);
    
    for(j=0;j<i;j++){
        k=3+j*5;
        who->set("longquest/quest"+j+"/"+questlst[k]+"/name",questlst[k+2]);
        who->set("longquest/quest"+j+"/"+questlst[k]+"/id",questlst[k+1]);
        who->set("longquest/quest"+j+"/"+questlst[k]+"/topic",questlst[k+3]);
        who->set("longquest/quest"+j+"/"+questlst[k]+"/ack",questlst[k+4]);
    }
    command("smile");
    command("say "+questlst[2]);
    return 1;
}

int fuming(object who)
{
    int reward;
    
    if(this_object()->query("class")!=who->query("class")||!who->query("longquest/name")){
        command("shake");
        command("say ��Ҫ��ʲô����");
        return 1;
    }
    
    if(who->query("longquest/index")!=who->query("longquest/count"))
    {
        command("angry");
        command("say ����û��ɾ������������ǲ��ǲ������ˣ�");
        return 1;
    }
    
    sscanf(who->query("longquest/reward"),"%d",reward);
    who->add("faith",reward/2+random(reward/2));
    reward=(int)who->query("combat_exp")/10000*reward;
    if(reward<8)reward=8;
    who->add("daoxing",reward/2+random(reward/2));
    reward/=4;
    who->add("potential",reward/2+random(reward/2));
    who->delete("longquest");
    command("smile");
    command("say ��ϲ�������һ��������ĵ�������ˣ�");
    return 1;
}
