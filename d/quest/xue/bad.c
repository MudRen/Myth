
//�������ﷸ

#include <ansi.h>
#include "place.h"
string* guainame=({
        "����","dacoit",
        "ǿ��","robber",
        "ɱ�˷�","killer",
        "��Ĺ��", "resurrecter",
        "ͨ�鷸", "misconducter",
        "�ݻ�", "incendiariser",
        "���", "bully",
        "���ٷ�", "robber",
        "�ɻ���", "rascal",
        "���У���", "crazy PKER",
});
        
string* xianname=({
        "���ٷ�", "robber",
        "����","dacoit",
        "ǿ��","robber",
        "ɱ�˷�","killer",
    	"��Ĺ��", "resurrecter",
        "ͨ�鷸", "misconducter",
        "�ݻ�", "incendiariser",
        "���", "bully",
        "�ɻ���", "rascal",
        "���У���", "crzay PKER",

});
string* prename=({
        "���� ",
        "ʮ���� ",
        "������� ",
        "�ٸ�ͨ�� ",
        "�����๼ ",
        });

int add_new_yao( object me);
void create()
{
    seteuid(getuid());
}

string query_yao(object me)
{
    mapping bad;
//yudian
//    int t;
//    t=me->query("bad_mudage");

    if(mapp(bad=me->query("bad"))){
        if(me->query("mud_age")-me->query("bad_mudage")<480
          && me->query("mud_age")>me->query("bad_mudage"))
//        if(time()<t+480)
         return ("������������ץ��"+bad["place"]+"��"+bad["name"]+"("+bad["id"]+")ô��\n");
        else{
         command("������û�ã����ٸ���һ�λ��ᣡ");
//         me->add("office_number",-1);
        }
    }
//yudian 
     if(me->query("mud_age")-me->query("bad_mudage")<60
        && me->query("mud_age")>me->query("bad_mudage"))
//     if(t>0 && time()<t+60)
        return ("�������ˣ�������Ϣһ�°ɣ�");  
    add_new_yao(me);
    bad=me->query("bad");
    if(bad["type"]=="xian")
       return ("����"+bad["name"]+"("+bad["id"]+")���ܵ�"+bad["place"]+"һ���������ڣ�\n�����ϰ�������ͷ�������ң�\n"); 
    else
       return ("����"+bad["name"]+"("+bad["id"]+")���ܵ�"+bad["place"]+"һ���������ڣ�\n�����ϰ�������ͷ�������ң�\n");
}

int add_new_yao( object me)
{
    string my_id,my_cls,type;
    string sname;
    string* yaoname;
    int my_exp,index;
    mapping skill_status;
    mapping bad;
    object where,yao;
        
    my_exp=me->query("combat_exp");
    my_cls=me->query("class");
    if(my_cls=="xian"||my_cls=="taoist"||my_cls=="dragon"||my_cls=="bonze"){
        type="xian";
        yaoname=guainame;
    }
    else {
        type="mo";
        yaoname=xianname;
    }
    
    index=random(sizeof(yaoname)/2)*2;
    
    bad=(["type" : type]);
    bad+=(["id" : yaoname[index+1] ]);
    sname=prename[random(sizeof(prename))]+yaoname[index];
    
    bad+=(["name" : sname]);
    
    if (skill_status = me->query_skills() ) {
      yaoname  = keys(skill_status);
   my_exp=0;
      for(index=0; index<sizeof(skill_status); index++) {
        if(skill_status[yaoname[index]]>my_exp &&yaoname[index]!="literate")
           my_exp=skill_status[yaoname[index]];
      }
    }
    
    index=random(sizeof(place))+1;
    yaoname=place[index];
    bad+=(["place" :yaoname[sizeof(yaoname)-1] ]);
    index=random(sizeof(yaoname)-2);
    sname=yaoname[sizeof(yaoname)-2]+yaoname[index];
    bad+=(["location" : sname]);
//yudian
    me->set("bad_mudage",me->query("mud_age"));
//    me->set("bad_mudage",time());

    me->set("bad",bad);
  
    if(!(where=find_object(bad["location"])))
             where=load_object(bad["location"]);

    yao=new(__DIR__"/bad");
    yao->move(where);
    yaoname=explode(bad["id"]," ");
    yaoname=({bad["id"]})+yaoname;
    if( me->query_temp("apply/name") )
        me->delete_temp("apply/name");    
    yao->set_name(me->name()+"��"+bad["name"],yaoname);
    yao->set("pre_killer",me);
    yao->init_skill(me->query("combat_exp"),my_exp,
         me->query("max_kee"),me->query("max_force"),
         me->query("max_sen"),me->query("max_mana"),bad["type"]);
    
    return 1;
}

int query_killyao(object me,string loc,string yaoid)
{
    string* loclist;
    string* loclist2;
    mapping bad=me->query("bad");
    if(!mapp(bad))return 0;
    loclist=explode(bad["location"],"/");
    loclist2=explode(loc,"/");
    return (loclist[sizeof(loclist)-2]==loclist2[sizeof(loclist2)-2]&&bad["id"]==yaoid);     
    return 0;   
}

 
