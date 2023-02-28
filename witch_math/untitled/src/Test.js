

export function Test({screenName, fullName}){
    return(
        <table>
        <tr>
            <th>screenName</th>
            <th>fullName</th>
        </tr>
            {screenName.map((name, i)=>
            <tr>
                <th>{name}</th>
                <th>{fullName[i]}</th>
            </tr>

        })


    </table>
    )
}